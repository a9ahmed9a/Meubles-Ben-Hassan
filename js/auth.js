// auth.js
import { initializeApp } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-app.js";	 
import { getAuth, signInAnonymously, onAuthStateChanged } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-auth.js";

// Your Firebase configuration
const firebaseConfig = {	  
    apiKey: "AIzaSyCM0smr-gYFHTHA6ecv0g0EU_k-kyMNavA",	  
    authDomain: "meublebenhassan.firebaseapp.com",	  
    projectId: "meublebenhassan",	  
    storageBucket: "meublebenhassan.appspot.com",	  
    messagingSenderId: "484610973479",	  
    appId: "1:484610973479:web:0d333ea7b55589643a9302"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth(app);

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
