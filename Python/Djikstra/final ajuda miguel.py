class Vertex:
    def __init__(self, cidade):
        self.id = cidade
        self.connectedTo = {}

    def addDestino(self, destino, tempo):
        self.connectedTo[destino] = tempo

    def getConnections(self):
        return self.connectedTo.keys()
    
    def getWeight(self, destino):
        return self.connectedTo.get(destino, float('inf'))


class Graph:
    def __init__(self):
        self.vertList = {}

    def addVertex(self, cidade):
        if cidade not in self.vertList:
            self.vertList[cidade] = Vertex(cidade)

    def addEdge(self, origem, destino, tempo):
        self.addVertex(origem)
        self.addVertex(destino)
        self.vertList[origem].addDestino(destino, tempo)


class Dijkstra:
    def __init__(self, graph):
        self.graph = graph

    def menor_tempo(self, origem, destino):
        if origem not in self.graph.vertList or destino not in self.graph.vertList:
            return None, None

        dist = {cidade: float('inf') for cidade in self.graph.vertList}
        anterior = {cidade: None for cidade in self.graph.vertList}
        dist[origem] = 0
        nao_visitados = list(self.graph.vertList.keys())

        while nao_visitados:
            u = min(nao_visitados, key=lambda cidade: dist[cidade])
            nao_visitados.remove(u)

            if dist[u] == float('inf'):
                break
            
            for vizinho in self.graph.vertList[u].getConnections():
                peso = self.graph.vertList[u].getWeight(vizinho)
                if dist[vizinho] > dist[u] + peso:
                    dist[vizinho] = dist[u] + peso
                    anterior[vizinho] = u

        if dist[destino] == float('inf'):
            return None, None

        caminho = []
        atual = destino
        while atual is not None:
            caminho.insert(0, atual)
            atual = anterior[atual]

        return caminho, dist[destino]


def processar_e_exibir():
    total_casos = int(input().strip())
    respostas = []

    for _ in range(total_casos):
        origem, destino = input().strip().split()
        grafo = Graph()

        for _ in range(int(input().strip())):
            cidade_origem, cidade_destino, tempo_viagem = input().strip().split()
            grafo.addEdge(cidade_origem, cidade_destino, float(tempo_viagem))

        dijkstra = Dijkstra(grafo)
        caminho, tempo_total = dijkstra.menor_tempo(origem, destino)

        if caminho is None:
            respostas.append(f"Origem:{origem} Destino:{destino}\nNão há rota possível.")
        else:
            trechos = [
                f"{caminho[i]} {caminho[i + 1]} {grafo.vertList[caminho[i]].getWeight(caminho[i + 1]):.1f}"
                for i in range(len(caminho) - 1)
            ]
            respostas.append(
                f"Origem:{origem} Destino:{destino}\n" + "\n".join(trechos) + f"\nTempo total: {tempo_total:.1f} horas."
            )

    print("\n\n".join(respostas))

processar_e_exibir()
