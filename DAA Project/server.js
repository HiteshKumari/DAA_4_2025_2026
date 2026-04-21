const express = require('express');
const cors = require('cors');

const app = express();
app.use(cors());
app.use(express.json());
app.use(express.static('public'));

const graph = {
    Warehouse: { Downtown: 5, IndustrialArea: 3 },
    Downtown: { Warehouse: 5, Mall: 2, Hospital: 4, University: 6, IndustrialArea: 4, HotelDistrict: 4 },
    IndustrialArea: { Warehouse: 3, Airport: 8, Downtown: 4, ResidentialSouth: 5 },
    Mall: { Downtown: 2, ResidentialNorth: 3, Hospital: 2 },
    Hospital: { Downtown: 4, Mall: 2, University: 1 },
    University: { Downtown: 6, Hospital: 1, ResidentialSouth: 2 },
    ResidentialNorth: { Mall: 3, Airport: 7 },
    ResidentialSouth: { University: 2, IndustrialArea: 5 },
    Airport: { IndustrialArea: 8, ResidentialNorth: 7, HotelDistrict: 3 },
    HotelDistrict: { Airport: 3, Downtown: 4 }
};

function dijkstra(start, end) {
    let dist = {};
    let prev = {};
    let visited = new Set();

    Object.keys(graph).forEach(node => dist[node] = Infinity);
    dist[start] = 0;

    while (true) {
        let closest = null;

        for (let node in dist) {
            if (!visited.has(node) && (closest === null || dist[node] < dist[closest])) {
                closest = node;
            }
        }

        if (closest === null || closest === end) break;

        visited.add(closest);

        for (let neighbor in graph[closest]) {
            let newDist = dist[closest] + graph[closest][neighbor];
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                prev[neighbor] = closest;
            }
        }
    }

    let path = [];
    let curr = end;

    while (curr) {
        path.unshift(curr);
        curr = prev[curr];
    }

    return { path, distance: dist[end] };
}

app.post('/route', (req, res) => {
    const { start, end } = req.body;
    const result = dijkstra(start, end);
    res.json(result);
});

app.listen(3000, () => {
    console.log("Server running on http://localhost:3000");
});