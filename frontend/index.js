let cart = JSON.parse(localStorage.getItem("cart")) || [];
function updateCartCount() {
    const cartCount = document.getElementById("cart-count");
    if (cartCount) {
        const totalItems = cart.reduce(
            (total, item) => total + item.quantity,
            0
        );
        cartCount.textContent = totalItems;
    }
}
// Load crops from C++ backend API

async function loadCrops() {
    const cropList = document.getElementById("crop-list");

    if (!cropList) return;

    try {
        const response = await fetch("http://localhost:18080/api/crops");

        if (!response.ok) {
            throw new Error("Unable to fetch crops");
        }

        const crops = await response.json();

        cropList.innerHTML = "";

        const cropImages = {
           "broccoli": "broccoli.png",
            "cabbage": "cabbage.png",
            "carrot": "carrot.png",
            "cauliflower": "cauliflower.png",
            "potato": "potato.png",
            "tomato": "tomato.png",
            "wheat": "wheat.png",
            "sweet potato": "sweet-potato.png",
            "apple": "apple.png",
            "rice": "rice.png"
        };

        crops.forEach(crop => {
            const card = document.createElement("section");
            card.className = "card";
            card.style.maxWidth = "320px";

            const imageName = cropImages[crop.cropName.trim().toLowerCase()];

            card.innerHTML = `
                <div class="card-body">

                    ${imageName ? `
                        <img src="images/${imageName}"
                             alt="${crop.cropName}"
                             style="width: 100%; height: 180px; object-fit: cover;">
                    ` : ""}

                    <h4 class="card-title">${crop.cropName}</h4>
                    <p>Category: ${crop.category}</p>
                    <p><strong>Price:</strong> ₹${crop.price}/kg</p>
                    <p><strong>Available:</strong> ${crop.quantity} kg</p>
                    <p><strong>Farmer ID:</strong> ${crop.farmerID}</p>

                    <button class="btn-solid theme-primary add-to-cart"
                        data-crop="${crop.cropName}"
                        data-price="${crop.price}">
                        Add to Cart
                    </button>

                </div>
            `;

            cropList.appendChild(card);
        });

    } catch (error) {
        console.error("Error loading crops:", error);
        cropList.textContent = "Unable to load crops.";
    }
}

function saveCart() {
    localStorage.setItem("cart", JSON.stringify(cart));
}
function addToCart(cropName, price) {
    const existingCrop = cart.find(item => item.name === cropName);
    if (existingCrop) {
        existingCrop.quantity++;
    } else {
        cart.push({
            name: cropName,
            price: price,
            quantity: 1
        });
    }
    saveCart();
    updateCartCount();
    alert(cropName + " added to cart!");
}
// Event delegation for dynamically loaded crop cards
document.addEventListener("click", function (event) {
    const button = event.target.closest(".add-to-cart");
    if (!button) return;
    const cropName = button.dataset.crop;
    const price = Number(button.dataset.price);
    addToCart(cropName, price);
});
updateCartCount();
function displayCart() {
    const cartItems = document.getElementById("cart-items");
    const subtotalElement = document.getElementById("cart-subtotal");
    if (!cartItems || !subtotalElement) {
        return;
    }
    cart = JSON.parse(localStorage.getItem("cart")) || [];
    if (cart.length === 0) {
        cartItems.innerHTML =
            '<p class="empty-cart">Your cart is empty.</p>';
        subtotalElement.textContent = "₹0";
        return;
    }
    cartItems.innerHTML = "";
    let subtotal = 0;
    cart.forEach((item, index) => {
const imageName = cropImages[crop.cropName.trim().toLowerCase()];
card.innerHTML = `
    <div class="card-body">
        ${imageName ? `
            <img src="images/${imageName}"
                 alt="${crop.cropName}"
                 style="width: 100%; height: 180px; object-fit: cover;">
        ` : ""}

        <h4 class="card-title">${crop.cropName}</h4>
        <p>Category: ${crop.category}</p>
        <p><strong>Price:</strong> ₹${crop.price}/kg</p>
        <p><strong>Available:</strong> ${crop.quantity} kg</p>
        <p><strong>Farmer ID:</strong> ${crop.farmerID}</p>

        <button class="btn-solid theme-primary add-to-cart"
            data-crop="${crop.cropName}"
            data-price="${crop.price}">
            Add to Cart
        </button>
    </div>
`;
    });
    subtotalElement.textContent = "₹" + subtotal;
    document.querySelectorAll(".remove-item").forEach(button => {
        button.addEventListener("click", function () {
            const index = Number(this.dataset.index);
            cart.splice(index, 1);
            localStorage.setItem("cart", JSON.stringify(cart));
            displayCart();
            updateCartCount();
        });
    });
}
displayCart();
loadCrops();