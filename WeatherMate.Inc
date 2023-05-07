<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>WeatherMate.Inc</title>
    <link rel="stylesheet" href="style.css" />
  </head>
  <body>
    <header>
      <h1>Weather Display</h1>
      <form>
        <input type="text" id="search-box" placeholder="Enter city name" />
        <button type="submit">Search</button>
      </form>
    </header>
    <main>
      <div id="weather-info"></div>
    </main>
    <footer>
      <p>&copy; 2023 WeatherMate.Inc</p>
    </footer>
    <script src="app.js"></script>
  </body>
</html>
<style>
     body{
        font-family: Arial, sans-serif;
        background-image:url('https://i.pinimg.com/originals/0e/f3/bb/0ef3bb66d9216fffcea9022628f7bb26.gif');
        background-color: white;
        margin: 0;
     }
     header{
        background-color: #333;
        color: #fff;
        padding: 1rem;
        display: flex;
        justify-content: space-between;
     }
     header form{
        display: flex;
     }
     header input[type="text"]{
        padding: 0.5rem;
        border-radius: 0.5rem;
        margin-right: 1rem;
     }
     header button[type="submit"]{
        padding: 0.5rem;
        border-radius: 0.5rem;
        background-color: #fff;
        color: #333;
        border: none;
        cursor: pointer;
     }
     header button[type="submit"]:hover{
        background-color: #ddd;
     }
     main{
        padding: 2rem;
        display: flex;
        justify-content: center;
        align-items: center;
        height: calc(100vh - 200px);
     }
     #weather-info {
        background-color: #fff;
        box-shadow: 0 0.5rem 1rem rgba(0, 0, 0, 0.1);
     }
     footer {
        background-color: #333;
        color: #fff;
        padding: 1rem;
        text-align: center;
     } 
</style>
<script>
const apiKey = '71b6a0f1e2255c11d5641707d26e8622';
const searchBox = document.querySelector('#search-box');
const weatherInfo = document.querySelector('#weather-info');
async function getWeatherData(city) {
  const response = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`);
  const data = await response.json();
  return data;
}
document.querySelector('form').addEventListener('submit', async (e) => {
  e.preventDefault();
  const city = searchBox.value.trim();
  if (city === '') return;
  const weatherData = await getWeatherData(city);
  console.log(weatherData);
  const cityName = weatherData.name;
  const weatherDescription = weatherData.weather[0].description;
  const temperature = weatherData.main.temp;
  const feelsLike = weatherData.main.feels_like;
  weatherInfo.innerHTML = `
    <h2>${cityName}</h2>
    <p>${weatherDescription}</p>
    <p>Temperature: ${temperature}&deg;C</p>
    <p>Feels like: ${feelsLike}&deg;C</p>
  `;
});
</script>