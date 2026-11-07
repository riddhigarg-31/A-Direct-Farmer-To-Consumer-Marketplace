let cart = [];
document.querySelectorAll(".add-to-cart").forEach(button => {
    button.addEventListener("click", function () {

        const cropName = this.dataset.crop;
        const price = Number(this.dataset.price);

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

       const cartCount = document.getElementById("cart-count");

        const totalItems = cart.reduce(
            (total, item) => total + item.quantity,
            0
        );

        cartCount.textContent = totalItems;

        alert(cropName + " added to cart!");

        console.log(cart);

    });

});