public class Baked implements State {
  Pizza pizza;

  public Baked(Pizza p) {
    this.pizza = p;
  }

  public void bake() {
    System.out.println("Can't bake a pizza already baked");
  }

  public void deliver() {
    System.out.println("Delivering the pizza...");
    this.pizza.setState(this.pizza.getDelivered());
  }

  public void botch() {
    System.out.println("Pizza was botched during baking... Pizza will eaten by the kitchen staff");
    this.pizza.setState(this.pizza.getBotched());
  }
}