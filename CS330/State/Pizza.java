public class Pizza {
  State cooked;
  State delivered;
  State baked;
  State botched;
  State state;

  public Pizza() {
    System.out.println("Prepping the pizza");
    cooked = new Cooked(this);
    delivered = new Baked(this);
    baked = new Delivered(this);
    botched = new Botched(this);
    state = cooked;
  }

  public void bake() {
    state.bake();
  }

  public void deliver() {
    state.deliver();
  }

  public void botch() {
    state.botch();
  }

  public void setState(State t) {
    this.state = t;
  }

  public State getCooked() {
    return cooked;
  }

  public State getBaked() {
    return baked;
  }

  public State getDelivered() {
    return delivered;
  }

  public State getBotched() {
    return botched;
  }
}