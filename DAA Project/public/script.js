const nodes = [
    "Warehouse", "Downtown", "IndustrialArea", "Mall",
    "Hospital", "University", "ResidentialNorth",
    "ResidentialSouth", "Airport", "HotelDistrict"
];

window.onload = () => {
    const start = document.getElementById("start");
    const end = document.getElementById("end");

    nodes.forEach(node => {
        start.innerHTML += `<option>${node}</option>`;
        end.innerHTML += `<option>${node}</option>`;
    });
};

async function findRoute() {
    const start = document.getElementById("start").value;
    const end = document.getElementById("end").value;

    const res = await fetch('/route', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ start, end })
    });

    const data = await res.json();

    document.getElementById("result").innerHTML = `
        <p><b>Shortest Path:</b> ${data.path.join(" → ")}</p>
        <p><b>Total Distance:</b> ${data.distance} km</p>
    `;
}