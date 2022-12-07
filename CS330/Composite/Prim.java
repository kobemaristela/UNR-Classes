public class Prim implements PrimComponent {
  public String name;
  public double volume;

  public Prim() {
  }

  public Prim(String name) {
    this.name = name;
  }

  public void print() {
    System.out.println("Item: " + this.name + "\t Volume: " + volume);
  }

  public void addComponent(PrimComponent newItem) {
    System.out.println("Error: Cannot add a component to a prim.");
  }

  public double getVolume() {
    return volume;
  }
}