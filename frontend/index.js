let cart = JSON.parse(localStorage.getItem("cart")) || [];
// Update cart count
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
// Save cart in browser
function saveCart() {
    localStorage.setItem("cart", JSON.stringify(cart));
}
// Add crop to cart
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
// Add button functionality
document.querySelectorAll(".add-to-cart").forEach(button => {
    button.addEventListener("click", function () {
        const cropName = this.dataset.crop;
        const price = Number(this.dataset.price);
        addToCart(cropName, price);
    });
});
// Update count when page loads
updateCartCount();