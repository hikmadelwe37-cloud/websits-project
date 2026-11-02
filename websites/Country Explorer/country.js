const countryGrid = document.getElementById("countryGrid");
const loadingDiv = document.getElementById("loading");
const errorDiv = document.getElementById("error");
const searchInput = document.getElementById("searchInput");
const regionFilter = document.getElementById("regionFilter");

let allCountries = [];

// 1. Fetch data from the REST Countries API using Async/Await
async function fetchCountries() {
  try {
    loadingDiv.style.display = "block";
    errorDiv.style.display = "none";

    const response = await fetch(
      "https://restcountries.com/v3.1/all?fields=name,capital,population,region,flags",
    );

    if (!response.ok) {
      throw new Error("Failed to retrieve country data from the server.");
    }

    allCountries = await response.json();
    loadingDiv.style.display = "none";

    // Initial render
    renderCountries(allCountries);
  } catch (error) {
    loadingDiv.style.display = "none";
    errorDiv.textContent = `Error: ${error.message}`;
    errorDiv.style.display = "block";
  }
}

// 2. Filter countries dynamically based on search text and region dropdown
function filterCountries() {
  const query = searchInput.value.toLowerCase();
  const selectedRegion = regionFilter.value;

  const filtered = allCountries.filter((country) => {
    const matchesName = country.name.common.toLowerCase().includes(query);
    const matchesRegion =
      selectedRegion === "" || country.region === selectedRegion;
    return matchesName && matchesRegion;
  });

  renderCountries(filtered);
}

// 3. Render country cards onto the DOM
function renderCountries(countries) {
  countryGrid.innerHTML = "";

  if (countries.length === 0) {
    countryGrid.innerHTML =
      "<p class='state-msg'>No countries match your search.</p>";
    return;
  }

  countries.forEach((country) => {
    const card = document.createElement("div");
    card.classList.add("country-card");

    // Handle cases where data might be missing safely
    const capital = country.capital ? country.capital[0] : "N/A";
    const population = country.population
      ? country.population.toLocaleString()
      : "N/A";

    card.innerHTML = `
            <img src="${country.flags.svg}" alt="Flag of ${country.name.common}">
            <h3>${country.name.common}</h3>
            <p><strong>Capital:</strong> ${capital}</p>
            <p><strong>Region:</strong> ${country.region}</p>
            <p><strong>Population:</strong> ${population}</p>
        `;

    countryGrid.appendChild(card);
  });
}

// Trigger initial data load when script runs
fetchCountries();
