import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;


public class Vertex {
    private String id;
    private int value;
    private Map<Vertex, Integer> connectedTo;

    public Vertex(String id, int value){
        this.id = id;
        this.value = value;
        this.connectedTo = new HashMap<>();
    }
    
    public void addNeighbor(Vertex neighbor, int weight){
        connectedTo.put(neighbor, weight);
    }

    public Set<Vertex> getConnections() {
        return connectedTo.keySet();
    }
    public String getId() {
        return id;
    }
    public int getValue(){
        return value;
    }

    public int getWeight(Vertex neighbor) {
        return connectedTo.get(neighbor);
    }

    @Override
    public String toString() {
        List<String> neighbors = new ArrayList<>();
        for (Vertex v : connectedTo.keySet()) { 
            neighbors.add(v.getId());
        }
        return id + " connectedTo: " + neighbors;
    }
}
