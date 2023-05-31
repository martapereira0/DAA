#include <iostream>
#include <vector>
#include <queue>

#define MAX_ROWS 255
#define MAX_COLS 255
#define NDIRS 4

using namespace std;

int numRows, numCols;

int dx[NDIRS] = {0, 0, +1, -1};
int dy[NDIRS] = {+1, -1, 0, 0};

struct Position {
    int y;
    int x;
    int distance;
};

// Verifica se uma posição (y, x) é válida dentro do mapa
bool isValidPosition(int y, int x) {
    if (y >= 0 && x >= 0 && y < numRows && x < numCols)
        return true;
    return false;
}

// Encontra as distâncias até os aeroportos no mapa
vector<int> findAirportDistances(string map[]) {
    vector<vector<int>> visited(numRows, vector<int>(numCols, -1)); // Matriz de visitados para marcar as posições já visitadas
    vector<int> distancesToAirport; // Vetor para armazenar as distâncias até aos aeroportos
    queue<Position> q; // Fila de posições

    // Preenche a fila inicial com as posições das nuvens ('#')
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (map[i][j] == '#')
                q.push({i, j, 0}); // Insere a posição na fila com distância zero
        }
    }

    while (!q.empty()) {
        Position current = q.front(); // Obter a posição atual da frente da fila
        q.pop(); // Remove a posição da fila

        int currentY = current.y; // Coordenada Y da posição atual
        int currentX = current.x; // Coordenada X da posição atual
        int distance = current.distance; // Distância até a posição atual

        for (int i = 0; i < NDIRS; i++) { // Para cada direção (cima, baixo, esquerda, direita)
            int nextY = currentY + dy[i]; // Calcula a próxima linha
            int nextX = currentX + dx[i]; // Calcula a próxima coluna

            // Verifica se a próxima posição é válida, se não contém uma nuvem ('#') e se ainda não foi visitada
            if (isValidPosition(nextY, nextX) && map[nextY][nextX] != '#' && visited[nextY][nextX] == -1) {
                if (map[nextY][nextX] == 'A')
                    distancesToAirport.push_back(distance + 1); // Se a próxima posição contém um aeroporto adiciona a distância até ele
                q.push({nextY, nextX, distance + 1}); // Adiciona a próxima posição à fila com a distância atualizada
                visited[nextY][nextX] = distance + 1; // Marca a próxima posição como visitada com a distância atualizada
            }
        }
    }

    return distancesToAirport; // Retorna o vetor de distâncias até os aeroportos
}

int main() {
    cin >> numRows >> numCols;
    string map[MAX_ROWS];
    for (int i = 0; i < numRows; i++) {
        cin >> map[i];
    }
    vector<int> airportDistances = findAirportDistances(map);
    cout << airportDistances[0] << " " << airportDistances[airportDistances.size() - 1] << "\n";
    return 0;
}
