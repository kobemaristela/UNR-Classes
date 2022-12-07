class PizzaDriver {
  public static void main(String[] args) {
    System.out.println("----Successful Pizza----");
    Pizza success_pizza = new Pizza();
    success_pizza.bake();
    success_pizza.deliver();

    System.out.println("\n----Failed Pizza | Prepping Phase----");
    Pizza bad_prep_pizza = new Pizza();
    bad_prep_pizza.botch();

    System.out.println("\n----Failed Pizza | Baking Phase----");
    Pizza bad_bake_pizza = new Pizza();
    bad_bake_pizza.bake();
    bad_bake_pizza.botch();

    System.out.println("\n----Failed Pizza | Delivering Phase----");
    Pizza bad_deliver_pizza = new Pizza();
    bad_deliver_pizza.bake();
    bad_deliver_pizza.deliver();
    bad_deliver_pizza.botch();

    System.out.println("\n----Logic Check | Pizza Double Bake----");
    Pizza check_bake_pizza = new Pizza();
    check_bake_pizza.bake();
    check_bake_pizza.bake();

    System.out.println("\n----Logic Check | Pizza Double Deliver----");
    Pizza check_deliver_pizza = new Pizza();
    check_deliver_pizza.bake();
    check_deliver_pizza.deliver();
    check_deliver_pizza.deliver();

    System.out.println("\n----Logic Check | Pizza Botched States----");
    Pizza check_botch_pizza = new Pizza();
    check_botch_pizza.bake();
    check_botch_pizza.botch(); // Results in end state

    check_botch_pizza.bake();
    check_botch_pizza.deliver();
    check_botch_pizza.botch();

  }
}