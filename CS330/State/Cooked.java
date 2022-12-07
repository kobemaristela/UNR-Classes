public class Cooked implements State {
  Pizza pizza;

  public Cooked(Pizza p) {
    this.pizza = p;
  }

  public void bake() {
    System.out.println("Baking the pizza...");
    this.pizza.setState(this.pizza.getBaked());
  }

  public void deliver() {
    System.out.println("Can't deliver a pizza not baked yet");
  }

  public void botch() {
    System.out.println("Pizza was botched during prepping... Redoing pizza preparation");
  }
}