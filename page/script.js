const title = document.getElementById("title");
const colorButton = document.getElementById("colorButton");

// 2. Listen for a click on the button
colorButton.addEventListener("click", function () {
  // 3. Change the text color of the h1 element to blue
  title.style.color = "red";
});

const darkButton = document.getElementById("darkButton");

darkButton.addEventListener("click", function() {
    document.body.classList.toggle("dark");
});