public class Botched implements State {
  Pizza pizza;

  public Botched(Pizza p) {
    this.pizza = p;
  }

  public void bake() {
    System.out.println("Can't bake a botched pizza... Kitchen staff already eating the pizza");
  }

  public void deliver() {
    System.out.println("Can't deliver a botched pizza... Kitchen staff already eating the pizza");
  }

  public void botch() {
    System.out.println("Pizza already botched... Kitchen staff already eating the pizza");
  }
}