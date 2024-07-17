/**
 * Data Catalog Project Starter Code - SEA Stage 2
 *
 * This file is where you should be doing most of your work. You should
 * also make changes to the HTML and CSS files, but we want you to prioritize
 * demonstrating your understanding of data structures, and you'll do that
 * with the JavaScript code you write in this file.
 * 
 * The comments in this file are only to help you learn how the starter code
 * works. The instructions for the project are in the README. That said, here
 * are the three things you should do first to learn about the starter code:
 * - 1 - Change something small in index.html or style.css, then reload your 
 *    browser and make sure you can see that change. 
 * - 2 - On your browser, right click anywhere on the page and select
 *    "Inspect" to open the browser developer tools. Then, go to the "console"
 *    tab in the new window that opened up. This console is where you will see
 *    JavaScript errors and logs, which is extremely helpful for debugging.
 *    (These instructions assume you're using Chrome, opening developer tools
 *    may be different on other browsers. We suggest using Chrome.)
 * - 3 - Add another string to the titles array a few lines down. Reload your
 *    browser and observe what happens. You should see a fourth "card" appear
 *    with the string you added to the array, but a broken image.
 * 
 */


// Array of car brands and their models
const cars = {
    "Audi": [ 
        {
            model: "Audi RS 3",
            description: "The RS 3 delivers dynamic handling with its RS torque splitter diverting available power individually to the rear wheels when needed. Via two drive select RS modes—RS performance or RS torque rear—the torque splitter can be adjusted to suit your drive.",
            engine: "2.5L TFSI® 5-cylinder",
            performance: "0-60 mph in 3.6 seconds",
            horsepower: "394 hp",
            epaEstimates: "19 city / 29 highway",
            imageSrc: "img/audi/audi-rs3.png"
        },
        {
            model: "Audi RS 5",
            description: "The RS 5 Coupe features a twin-turbo, 2.9-litre V6 engine puts out 444 HP and 442 lb-ft of torque to all four wheels.",
            engine: "2.9L TFSI® V6 biturbo engine",
            performance: "0-60 mph in 3.7 seconds",
            horsepower: "444 hp",
            epaEstimates: "18 city / 25 highway",
            imageSrc: "img/audi/audi-rs5.png"
        },
        {
            model: "Audi RS 7",
            description: "With revisions to its 4-litre, 8-cylinder engine featuring twin-turbochargers nested in the V, the power of the 2024 RS 7 performance is clear.",
            engine: "4.0L TFSI® V8 biturbo engine",
            performance: "0-60 mph in 3.3 seconds",
            horsepower: "591 hp",
            epaEstimates: "15 city / 22 highway",
            imageSrc: "img/audi/audi-rs7.png"
        },
        {
            model: "Audi R8",
            description: "The R8 Coupe features a 5.2-litre V10 engine that puts out 562 HP and 406 lb-ft of torque to the rear wheels.",
            engine: "5.2L V10 FSI® engine",
            performance: "0-60 mph in 3.1 seconds",
            horsepower: "562 hp",
            epaEstimates: "13 city / 20 highway",
            imageSrc: "img/audi/audi-r8.png"
        },
        {
            model: "Audi e-tron GT",
            description: "The e-tron GT is a fully electric sports car that features a 93.4 kWh battery and two electric motors that produce 637 HP.",
            engine: "Dual electric motors",
            performance: "0-60 mph in 3.1 seconds",
            horsepower: "637 hp",
            epaEstimates: "76 city / 78 highway",
            imageSrc: "img/audi/audi-etron-gt.png"
        }
    ],
    "BMW": [
        {
            model: "BMW M2",
            description: "The M2 Coupe meets that request beyond measure. The 3.0-liter BMW M TwinPower Turbo inline 6-cylinder engine roars with refined power.",
            engine: "3.0L M TwinPower Turbo inline 6-cylinder",
            performance: "0-60 mph in 3.9 seconds",
            horsepower: "405 hp",
            epaEstimates: "18 city / 24 highway",
            imageSrc: "img/bmw/bmw-m2.png"
        },
        {
            model: "BMW M3 Competition xDrive Sedan",
            description: "The incredible 3.0-liter BMW M TwinPower Turbo inline 6-cylinder engine reaches peak performance in the Competition xDrive model with a stunning 503 hp. A manual transmission comes standard for the performance-obsessed, while the standard 8-speed M Sport Transmission in the M3 Competition models offers quick, precise shifting.",
            engine: "3.0L M TwinPower Turbo inline 6-cylinder",
            performance: "0-60 mph in 3.4 seconds",
            horsepower: "503 hp",
            epaEstimates: "16 city / 23 highway",
            imageSrc: "img/bmw/bmw-m3.png"
        },
        {
            model: "BMW M4 Competition xDrive Coupe",
            description: "The high-performance BMW M4 Competition xDrive Coupe boasts up to 523 hp thanks to the 3.0-liter BMW M TwinPower Turbo inline 6-cylinder gasoline engine. Equally impressive, the BMW M4 Competition xDrive Coupe includes the same powerhouse engine with rear-wheel drive. Both vehicles guarantee exceptional driving dynamics – both on the road and racetrack.",
            engine: "3.0L M TwinPower Turbo inline 6-cylinder",
            performance: "0-60 mph in 3.4 seconds",
            horsepower: "523 hp",
            epaEstimates: "16 city / 23 highway",
            imageSrc: "img/bmw/bmw-m4.png"
        },
        {
            model: "BMW M8 Competition Coupe",
            description: "The BMW M8 Competition Coupe is more than a perfectly-tuned sports car. With an ideal weight distribution, rear-wheel drive, and M xDrive system, this high-performance coupe is made to conquer every road.",
            engine: "4.4L M TwinPower Turbo V-8",
            performance: "0-60 mph in 3.0 seconds",
            horsepower: "617 hp",
            epaEstimates: "15 city / 21 highway",
            imageSrc: "img/bmw/bmw-m8.png"
        }
    ],
    "Mercedes": [
        {
            model: "Mercedes-AMG C 63 S Coupe",
            description: "The Mercedes-AMG C 63 S Coupe is a high-performance machine that boasts a 4.0-liter V8 biturbo engine that produces 503 hp and 516 lb-ft of torque.",
            engine: "4.0L V8 biturbo engine",
            performance: "0-60 mph in 3.7 seconds",
            horsepower: "503 hp",
            epaEstimates: "16 city / 24 highway",
            imageSrc: "img/mercedes/c63.png"
        },
        {
            model: "Mercedes-AMG E 63 S Sedan",
            description: "The Mercedes-AMG E 63 S Sedan is a high-performance machine that boasts a 4.0-liter V8 biturbo engine that produces 603 hp and 627 lb-ft of torque.",
            engine: "4.0L V8 biturbo engine",
            performance: "0-60 mph in 3.0 seconds",
            horsepower: "603 hp",
            epaEstimates: "16 city / 23 highway",
            imageSrc: "img/mercedes/e63.png"
        },
        {
            model: "Mercedes-AMG GT Coupe",
            description: "The Mercedes-AMG GT Coupe is a high-performance machine that boasts a 4.0-liter V8 biturbo engine that produces 577 hp and 590 lb-ft of torque.",
            engine: "4.0L V8 biturbo engine",
            performance: "0-60 mph in 3.1 seconds",
            horsepower: "577 hp",
            epaEstimates: "15 city / 20 highway",
            imageSrc: "img/mercedes/gt.png"
        }
    ],
    "Porsche": [
        {
            model: "Porsche Cayman GTS",
            description: "The 718 GTS 4.0 models offer an enormous performance spectrum. Guaranteed by the powerful 4.0-liter six-cylinder naturally aspirated engine with its full 394 hp at 7,000 rpm. The maximum torque: 309 lb-ft. Top track speed: 182 mph.",
            engine: "4.0L six-cylinder",
            performance: "0-60 mph in 4.3 seconds",
            horsepower: "394 hp",
            epaEstimates: "17 city / 24 highway",
            imageSrc: "img/porsche/porsche-taycan-gts.png"
        },
        {
            model: "Porsche Cayman GT4RS",
            description: "The 718 Cayman GT4 RS is a razor-sharp track tool. A highly agile mid-engine concept with 4.0-liter displacement and a six-cylinder naturally aspirated engine. Six individual throttle valves for a direct response. A high-revving concept that easily scratches the 9,000 mark. An output of 493 hp. Rational, not always.",
            engine: "4.0L six-cylinder",
            performance: "0-60 mph in 3.2 seconds",
            horsepower: "493 hp",
            epaEstimates: "16 city / 23 highway",
            imageSrc: "img/porsche/porsche-cayman-gt4rs.png"
        },
        {
            model: "Porsche 911 Turbo S",
            description: "The 911 Turbo S is powered by a 3.8-liter twin-turbo flat-six engine that produces 640 hp and 590 lb-ft of torque.",
            engine: "3.8L twin-turbo flat-six engine",
            performance: "0-60 mph in 2.6 seconds",
            horsepower: "640 hp",
            epaEstimates: "15 city / 20 highway",
            imageSrc: "img/porsche/porsche-911-turbos.png"
        },
        {
            model: "Porsche 911 GT3",
            description: "The 911 GT3 is powered by a 4.0-liter naturally aspirated flat-six engine that produces 502 hp and 346 lb-ft of torque.",
            engine: "4.0L naturally aspirated flat-six engine",
            performance: "0-60 mph in 3.2 seconds",
            horsepower: "502 hp",
            epaEstimates: "15 city / 20 highway",
            imageSrc: "img/porsche/porsche-911-gt3.png"
        },
        {
            model: "Porsche 911 GT3 RS",
            description: "The 911 GT3 RS is powered by a 4.0-liter naturally aspirated flat-six engine that produces 518 hp and 3342 lb-ft of torque.",
            engine: "4.0L naturally aspirated flat-six engine",
            performance: "0-60 mph in 3.0 seconds",
            horsepower: "518 hp",
            epaEstimates: "15 city / 20 highway",
            imageSrc: "img/porsche/porsche-911-gt3rs.png"
        },
        {
            model: "Porsche Taycan GTS",
            description: "The Taycan GTS is a fully electric sports car that features a 93.4 kWh battery and two electric motors that produce 590 hp.",
            engine: "Dual electric motors",
            performance: "0-60 mph in 3.5 seconds",
            horsepower: "590 hp",
            epaEstimates: "68 city / 70 highway",
            imageSrc: "img/porsche/porsche-taycan-gts.png"
        },
        {
            model: "Porsche Taycan Turbo S",
            description: "The Taycan Turbo S is a fully electric sports car that features a 93.4 kWh battery and two electric motors that produce 750 hp.",
            engine: "Dual electric motors",
            performance: "0-60 mph in 2.6 seconds",
            horsepower: "750 hp",
            epaEstimates: "68 city / 70 highway",
            imageSrc: "img/porsche/porsche-taycan-turbo-s.png"
        }
    ],
    "Tesla": [
        {
            model: "Tesla Model 3 Performance",
            description: "The Model 3 Performance is a fully electric sedan that features a 75 kWh battery and two electric motors that produce 455 hp.",
            engine: "Dual electric motors",
            performance: "0-60 mph in 3.1 seconds",
            horsepower: "455 hp",
            epaEstimates: "134 city / 124 highway",
            imageSrc: "img/tesla/tesla-model3-performance.png"
        },
        {
            model: "Tesla Model S Plaid",
            description: "The Model S Plaid is a fully electric sedan that features a 100 kWh battery and three electric motors that produce 1,020 hp.",
            engine: "Tri electric motors",
            performance: "0-60 mph in 1.9 seconds",
            horsepower: "1,020 hp",
            epaEstimates: "101 city / 105 highway",
            imageSrc: "img/tesla/tesla-model-s-plaid.png"
        }
    ]
};

// This function updates the about section of car details
function updateAboutSection(carName) {
    const car = cars[carName];
    if (car) {
        const titleElement = document.querySelector('.about__title');
        titleElement.textContent = car.model;

        const engineElement = document.querySelector('.about__engine');
        engineElement.textContent = "Engine: " + car.engine;

        const performanceElement = document.querySelector('.about__performance');
        performanceElement.textContent = "Performance: " + car.performance;
    }
}

// This function updates the home section when clicking the specific car model
function updateHomeSection(car) {
    const homeSubtitleElement = document.querySelector('.home__subtitle');
    homeSubtitleElement.textContent = car.model;

    const homeCarNumberElements = document.querySelectorAll('.home__car-number');
    homeCarNumberElements[0].textContent = car.horsepower;
    homeCarNumberElements[1].textContent = car.engine;
    homeCarNumberElements[2].textContent = car.epaEstimates;

    const homeCarNameElements = document.querySelectorAll('.home__car-name');
    homeCarNameElements[0].textContent = "HORSEPOWER";
    homeCarNameElements[1].textContent = "ENGINE";
    homeCarNameElements[2].textContent = "EPA ESTIMATES";

    const homeImgElement = document.querySelector('.home__img');
    homeImgElement.src = car.imageSrc;

    const startButton = document.querySelector('.home__button');
    startButton.href = "#about";

    const homeCarDescription = document.querySelector('.home__car-tooltip p');
    homeCarDescription.textContent = car.description;
}

const homeImgElement = document.querySelector('.home__img');
const homeCarTooltip = document.querySelector('.home__car-tooltip');

function displayCarOptions() {
    const aboutDataContainer = document.querySelector('.about__container.grid');

    for (const brand in cars) {
        const carList = cars[brand];
        
        const carMakeSection = document.createElement('div');
        carMakeSection.classList.add('car-make');

        const carMakeTitle = document.createElement('h2');
        carMakeTitle.classList.add('car-make__title');
        carMakeTitle.textContent = brand;
        // appendChild is used to add the carMakeTitle to the carMakeSection
        carMakeSection.appendChild(carMakeTitle);

        const carOptionsContainer = document.createElement('div');
        carOptionsContainer.classList.add('car-options');

        carList.forEach(car => {
            const carOption = document.createElement('div');
            carOption.classList.add('car-option');
            
            const carModel = document.createElement('h3');
            carModel.textContent = car.model;
            // appendChild is used to add the carModel to the carOption
            carOption.appendChild(carModel);
            
            // Event listener to update car details and move back to home section
            carOption.addEventListener('click', () => {
                updateHomeSection(car);
                const targetSection = document.getElementById('home');
                targetSection.scrollIntoView({ behavior: 'smooth' });
            });

            // appendChild is used to add the carOption to the carOptionsContainer
            carOptionsContainer.appendChild(carOption);
        });

        // appendChild is used to add the carOptionsContainer to the carMakeSection
        carMakeSection.appendChild(carOptionsContainer);

        // Adding click event listener to the carMakeSection itself
        carMakeSection.addEventListener('click', () => {
            carOptionsContainer.classList.toggle('show-options');
        });

        // appendChild is used to add the carMakeSection to the aboutDataContainer
        aboutDataContainer.appendChild(carMakeSection);
    }
}

window.addEventListener('load', displayCarOptions);

// Header moves when scrolling
const scrollHeader = () => {
    const header = document.getElementById('header');
    this.scrollY >= 50 ? header.classList.add('scroll-header') 
                       : header.classList.remove('scroll-header');
};

window.addEventListener('scroll', scrollHeader);

// Start button scrolls the page to the about section
const startButton = document.querySelector('.home__button');

startButton.addEventListener('click', (event) => {
    event.preventDefault();

    const targetSection = document.getElementById('about');
    targetSection.scrollIntoView({ behavior: 'smooth' });
});


/* ----------COMPARISON FIELD---------- */
// Dropdown menu for cars
function populateAddCarDropdown() {
    const addCarSelect = document.getElementById("add-car");
    addCarSelect.innerHTML = '<option value=""></option>';

    Object.values(cars).forEach(brand => {
        brand.forEach(car => {
            const option = document.createElement("option");
            option.value = car.model;
            option.textContent = car.model;
            addCarSelect.appendChild(option);
        });
    });
}

function addCar() {
    const selectedCarModel = document.getElementById("add-car").value.trim();
    if (selectedCarModel) {
        addCarToComparison(selectedCarModel);
    } else {
        console.log("Please select a car.");
    }
}

const addRemoveCarForm = document.getElementById("add-remove-car-form");
addRemoveCarForm.addEventListener("submit", (event) => {
    event.preventDefault();
    const newCarModel = document.getElementById("add-car").value.trim();
    if (newCarModel) {
        addCarToComparison(newCarModel);
        document.getElementById("add-car").value = "";
    }
});

function addCarToComparison(model) {
    const brand = model.split(" ")[0];
    const car = cars[brand].find(car => car.model === model);
    if (car) {
        // Creates a new car card
        const comparisonContainer = document.getElementById("comparison-container");
        const carCard = document.createElement("div");
        carCard.classList.add("car-card");
        carCard.innerHTML = `
            <p>${car.model}</p>
            <button class="remove-car">Remove</button>
        `;
        comparisonContainer.appendChild(carCard);

        const removeButton = carCard.querySelector(".remove-car");
        removeButton.addEventListener("click", () => {
            carCard.remove();
            populateRemoveCarDropdown();
        });
    } else {
        console.log(`Car "${model}" not found.`);
    }
}

function compareCars() {
    // Gets all of the selected cars
    const selectedCars = document.querySelectorAll(".car-card");
    const comparisonContainer = document.getElementById("comparison-container");

    comparisonContainer.innerHTML = "";

    if (selectedCars.length < 2) {
        comparisonContainer.innerHTML = "<p>Please select at least two cars to compare.</p>";
        return;
    }

    const selectedCarModels = Array.from(selectedCars).map(car => car.querySelector("p").textContent);
    
    const comparisonDetails = selectedCarModels.map(model => {
        const brand = model.split(" ")[0];
        return cars[brand].find(car => car.model === model);
    });

    // Displays the comparison details
    comparisonContainer.innerHTML += "<h3>Comparison Details</h3>";
    comparisonDetails.forEach(car => {
        comparisonContainer.innerHTML += `
            <div class="comparison-details">
                <img src="${car.imageSrc}" alt="${car.model}">
                <p><strong>${car.model}</strong></p>
                <p><strong>HORSEPOWER:</strong> ${car.horsepower}</p>
                <p><strong>ENGINE:</strong> ${car.engine}</p>
                <p><strong>PERFORMANCE:</strong> ${car.performance}</p>
                <p><strong>EPA ESTIMATES:</strong> ${car.epaEstimates}</p>
            </div>
        `;
    });
}

// Event listener for the compare button
const clearComparisonButton = document.getElementById("clear-comparison-button");
clearComparisonButton.addEventListener("click", clearComparison);

function clearComparison() {
    const comparisonContainer = document.getElementById("comparison-container");
    comparisonContainer.innerHTML = "";
    populateAddCarDropdown(); 
}

window.addEventListener('load', populateAddCarDropdown);