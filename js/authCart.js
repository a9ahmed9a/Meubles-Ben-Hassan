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

async function fetchAndDisplayData() {
    signInAnonymously(auth)
        .then(() => {
            console.log("Guest signed in");
        })
        .catch((error) => {
            const errorCode = error.code;
            const errorMessage = error.message;
            console.error(`Guest sign-in error: ${errorCode} - ${errorMessage}`);
        });
    const user = auth.currentUser;
    if (user) {
        const userId = user.uid;
    
    const mobileView = document.querySelector('.row.d-md-none');
    const desktopView = document.querySelector('.site-blocks-table tbody');
    
    try {
        const docRef = doc(firestore, 'carts', userId);
        const snapshot = await getDoc(docRef);

        snapshot.forEach((doc) => {

        const data = doc.data();
        
        const mobileForm = document.createElement('form');
        mobileForm.method = 'post';
        mobileForm.classList.add('col-md-12');
        
        const mobileRow = document.createElement('div');
        mobileRow.classList.add('row', 'justify-content-center');
        
        const mobileImgDiv = document.createElement('div');
        mobileImgDiv.classList.add('col-2', 'p-0');
        const mobileImg = document.createElement('img');
        mobileImg.src = data.image;
        mobileImg.alt = "Image";
        mobileImg.classList.add('w-100');
        mobileImgDiv.appendChild(mobileImg);
        mobileRow.appendChild(mobileImgDiv);
        
        const mobileDescDiv = document.createElement('div');
        mobileDescDiv.classList.add('col-4', 'p-0');
        const mobileDescNameDiv = document.createElement('div');
        mobileDescNameDiv.classList.add('col-md-6');
        const mobileName = document.createElement('h5');
        mobileName.textContent = data.name;
        mobileDescNameDiv.appendChild(mobileName);
        mobileDescDiv.appendChild(mobileDescNameDiv);
        const mobileDescPriceDiv = document.createElement('div');
        mobileDescPriceDiv.classList.add('col-md-6');
        const mobilePrice = document.createElement('p');
        mobilePrice.textContent = `$${data.price}`;
        mobileDescPriceDiv.appendChild(mobilePrice);
        mobileDescDiv.appendChild(mobileDescPriceDiv);
        mobileRow.appendChild(mobileDescDiv);
        
        const mobileQtyDiv = document.createElement('div');
        mobileQtyDiv.classList.add('col-3', 'p-0', 'd-flex', 'align-items-center');
        const mobileQtyContainer = document.createElement('div');
        mobileQtyContainer.classList.add('d-flex', 'justify-content-center', 'align-items-center');
        const mobileQtyInputGroup = document.createElement('div');
        mobileQtyInputGroup.classList.add('input-group', 'mb-3', 'd-flex', 'align-items-center', 'quantity-container');
        mobileQtyInputGroup.style.maxWidth = '140px';
        const mobileQtyInput = document.createElement('input');
        mobileQtyInput.type = 'number';
        mobileQtyInput.classList.add('ms-1', 'me-1', 'form-control', 'text-center', 'quantity-amount');
        mobileQtyInput.value = '1';
        mobileQtyInputGroup.appendChild(mobileQtyInput);
        mobileQtyContainer.appendChild(mobileQtyInputGroup);
        mobileQtyDiv.appendChild(mobileQtyContainer);
        mobileRow.appendChild(mobileQtyDiv);
        
        const mobileRemoveDiv = document.createElement('div');
        mobileRemoveDiv.classList.add('col-1', 'd-flex', 'align-items-center', 'mb-3');
        const mobileRemoveBtn = document.createElement('a');
        mobileRemoveBtn.href = '#';
        mobileRemoveBtn.classList.add('btn', 'btn-2', 'btn-black', 'btn-sm');
        mobileRemoveBtn.textContent = 'X';
        mobileRemoveDiv.appendChild(mobileRemoveBtn);
        mobileRow.appendChild(mobileRemoveDiv);
        
        mobileForm.appendChild(mobileRow);
        mobileView.appendChild(mobileForm);
        
        // Desktop View
        const desktopRow = document.createElement('tr');
        
        const desktopImgTd = document.createElement('td');
        desktopImgTd.classList.add('product-thumbnail');
        const desktopImg = document.createElement('img');
        desktopImg.src = data.image;
        desktopImg.alt = 'Image';
        desktopImg.classList.add('w-105', 'img-fluid');
        desktopImgTd.appendChild(desktopImg);
        desktopRow.appendChild(desktopImgTd);
        
        const desktopNameTd = document.createElement('td');
        desktopNameTd.classList.add('product-name');
        const desktopName = document.createElement('h2');
        desktopName.classList.add('h5', 'text-black');
        desktopName.textContent = data.name;
        desktopNameTd.appendChild(desktopName);
        desktopRow.appendChild(desktopNameTd);
        
        const desktopPriceTd = document.createElement('td');
        desktopPriceTd.textContent = `$${data.price}`;
        desktopRow.appendChild(desktopPriceTd);
        
        const desktopQtyTd = document.createElement('td');
        const desktopQtyContainer = document.createElement('div');
        desktopQtyContainer.classList.add('d-flex', 'justify-content-center', 'align-items-center');
        const desktopQtyInputGroup = document.createElement('div');
        desktopQtyInputGroup.classList.add('input-group', 'mb-3', 'd-flex', 'align-items-center', 'quantity-container');
        desktopQtyInputGroup.style.maxWidth = '140px';
        const desktopQtyInput = document.createElement('input');
        desktopQtyInput.type = 'number';
        desktopQtyInput.classList.add('ms-1', 'me-1', 'form-control', 'text-center', 'quantity-amount');
        desktopQtyInput.value = '1';
        desktopQtyInputGroup.appendChild(desktopQtyInput);
        desktopQtyContainer.appendChild(desktopQtyInputGroup);
        desktopQtyTd.appendChild(desktopQtyContainer);
        desktopRow.appendChild(desktopQtyTd);
        
        const desktopRemoveTd = document.createElement('td');
        const desktopRemoveBtn = document.createElement('a');
        desktopRemoveBtn.href = '#';
        desktopRemoveBtn.classList.add('btn', 'btn-2', 'btn-black', 'btn-sm');
        desktopRemoveBtn.textContent = 'X';
        desktopRemoveTd.appendChild(desktopRemoveBtn);
        desktopRow.appendChild(desktopRemoveTd);
        
        desktopView.appendChild(desktopRow);
    });
    } catch (error) {
    console.error("Error fetching data: ", error);
    }
}else{
    console.log("user !!!!");
}
};

window.onload = fetchAndDisplayData;