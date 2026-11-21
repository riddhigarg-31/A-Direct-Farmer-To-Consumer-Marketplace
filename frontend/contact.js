// Dedicated logic for contact.html
document.addEventListener('DOMContentLoaded', () => {
    const contactForm = document.getElementById('contactForm');
    
    if (contactForm) {
        contactForm.addEventListener('submit', function(event) {
            // Prevent default form submission reload
            event.preventDefault();
            
            // Show clean success pop-up
            alert('🎉 Message Sent Successfully! We will get back to you soon.');
            
            // Clear input fields
            contactForm.reset();
        });
    }
});