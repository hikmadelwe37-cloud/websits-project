document.addEventListener("DOMContentLoaded", () => {
  const contactBtn = document.getElementById("contactBtn");

  if (contactBtn) {
    contactBtn.addEventListener("click", () => {
      const contactSection = document.getElementById("contact");
      contactSection.scrollIntoView({ behavior: "smooth" });
    });
  }
});
const hamburger = document.getElementById('hamburger');
const navMenu = document.getElementById('nav-menu');

hamburger.addEventListener('click', () => {
  navMenu.classList.toggle('active');
});

// Close menu when a link is clicked
document.querySelectorAll('.nav-menu a').forEach(link => {
  link.addEventListener('click', () => {
    navMenu.classList.remove('active');
  });
});
