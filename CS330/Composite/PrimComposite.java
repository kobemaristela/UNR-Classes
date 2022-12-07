import java.util.ArrayList;

public class PrimComposite implements PrimComponent {
  ArrayList<PrimComponent> items;
  String description;
  double totalVolume;

  public PrimComposite(String d) {
    this.items = new ArrayList<PrimComponent>();
    this.description = d;
  }

  public void print() {
    System.out.println("\nComposite: " + description);
    System.out.println("Total Volume: " + totalVolume);
    System.out.println("==========");
    
    for (PrimComponent item : items) {
      item.print();
    }
  }

  public void addComponent(PrimComponent newItem) {
    items.add(newItem);
    totalVolume += newItem.getVolume();
  }

  public double getVolume() {
    return totalVolume;
  }
}