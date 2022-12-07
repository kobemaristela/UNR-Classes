public class Delivered implements State {
  Pizza pizza;

  public Delivered(Pizza p) {
    this.pizza = p;
  }

  public void bake() {
    System.out.println("Can't bake a pizza already delivered");
  }

  public void deliver() {
    System.out.println("Can't deliver a pizza already delivered");
  }

  public void botch() {
    System.out.println("Pizza already delivered");
  }
}