// auth.js
import { initializeApp } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-app.js";	 
import { getAuth, signInAnonymously, onAuthStateChanged } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-auth.js";
import { getFirestore, doc, setDoc, getDoc, updateDoc } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-firestore.js";

// Your Firebase configuration
const firebaseConfig = {	  
    apiKey: "AIzaSyCM0smr-gYFHTHA6ecv0g0EU_k-kyMNavA",	  
    authDomain: "meublebenhassan.firebaseapp.com",	  
    projectId: "meublebenhassan",	  
    storageBucket: "meublebenhassan.appspot.com",	  
    messagingSenderId: "484610973479",	  
    appId: "1:484610973479:web:0d333ea7b55589643a9302",
    databaseURL: "https://meublebenhassan-default-rtdb.europe-west1.firebasedatabase.app" // Ensure this URL is correct
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth(app);
const firestore = getFirestore(app);

// Function to handle guest sign-in
const signInAsGuest = () => {
    signInAnonymously(auth)
        .then(() => {
            console.log("Guest signed in");
        })
        .catch((error) => {
            const errorCode = error.code;
            const errorMessage = error.message;
            console.error(`Guest sign-in error: ${errorCode} - ${errorMessage}`);
        });
};

// Check auth state on page load
onAuthStateChanged(auth, (user) => {
    if (!user) {
        signInAsGuest();
    } else {
        console.log("User signed in:", user);
    }
});

const addItemToCart = async (itemName, quantity) => {
    const user = auth.currentUser;
    if (user) {
        const userId = user.uid;
        const cartDocRef = doc(firestore, 'carts', userId);

        try {
            const cartDoc = await getDoc(cartDocRef);
            let cartItems = {};
            if (cartDoc.exists()) {
                cartItems = cartDoc.data();
            }

            // Update cart items
            cartItems[itemName] = {
                name: itemName,
                quantity: quantity
            };

            // Save the updated cart
            await setDoc(cartDocRef, cartItems);
            console.log("Item added to cart:", cartItems[itemName]);
        } catch (error) {
            console.error("Error adding item to cart:", error);
        }
    } else {
        console.error("User is not authenticated");
    }
};

window.addItemToCart = addItemToCart;