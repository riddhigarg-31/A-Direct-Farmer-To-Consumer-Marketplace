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

document.querySelectorAll(".add-to-cart").forEach(button => {
    button.addEventListener("click", function () {
        const cropName = this.dataset.crop;
        const price = Number(this.dataset.price);
        addToCart(cropName, price);
    });
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
        const itemTotal = item.price * item.quantity;
        subtotal += itemTotal;

        const row = document.createElement("div");
        row.className = "cart-item";

        row.innerHTML = `
            <h5>${item.name}</h5>
            <p>Price: ₹${item.price}/kg</p>
            <p>Quantity: ${item.quantity} kg</p>
            <p class="item-total">Total: ₹${itemTotal}</p>            <button class="btn btn-danger remove-item"
                    data-index="${index}">
                Remove
            </button>
        `;

        cartItems.appendChild(row);
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
