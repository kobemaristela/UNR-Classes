

// Scripts - Update Buttons
let breakfast = document.getElementById("btn-breakfast");
let lunch = document.getElementById("btn-lunch");
let dinner = document.getElementById("btn-dinner");


const refreshMeals = async () => {
    const res = await fetch("getTodayMeals", {method: 'GET'});
    const data = await res.json();

    if (data.breakfast) {
        breakfast.disabled = true;
        breakfast.style.background = "rgb(13, 212, 103)";
        breakfast.style.color = "rgb(255, 255, 255)";
        breakfast.style.border = "2px solid rgb(13, 212, 103)";
        breakfast.style.textDecoration = "none";
        breakfast.textContent = "- I'M FULL";
    }

    if (data.lunch) {
        lunch.disabled = true;
        lunch.style.background = "rgb(13, 212, 103)";
        lunch.style.color = "rgb(255, 255, 255)";
        lunch.style.border = "2px solid rgb(13, 212, 103)";
        lunch.style.textDecoration = "none";
        lunch.textContent = "- SOOO STUFFED";
    }

    if (data.dinner) {
        dinner.disabled = true;
        dinner.style.background = "rgb(13, 212, 103)";
        dinner.style.color = "rgb(255, 255, 255)";
        dinner.style.border = "2px solid rgb(13, 212, 103)";
        dinner.style.textDecoration = "none";
        dinner.textContent = "- YUMMMMYYYYY";
    }
};

refreshMeals();


breakfast.addEventListener("click", async (e) => {
  e.preventDefault();

  await fetch("setBreakfast", {method: 'POST'});
  window.location.reload(true);
});

lunch.addEventListener("click", async (e) => {
    e.preventDefault();
  
    await fetch("setLunch", {method: 'POST'});
    window.location.reload(true);
});

dinner.addEventListener("click", async (e) => {
    e.preventDefault();
  
    await fetch("setDinner", {method: 'POST'});
    window.location.reload(true);
});