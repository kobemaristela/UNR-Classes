class Main {
  public static void main(String[] args) {
    // Grabs existing schedule from database
    Scheduler model  = retrieveScheduleFromDatabase();

    // Setup view for console
    ScheduleView view = new ScheduleView();

    ScheduleController controller = new ScheduleController(model, view);  // interacts between model and view

    // Orginal Schedule Output
    System.out.println("-------Orginal Schedule-------");
    controller.updateView();

    // New Schedule Output
    System.out.println("\n-------New Schedule-------");
    controller.setClassName("Design Patterns");
    controller.setClassNumber("330");
    controller.setClassDescription("Introduction to design patterns: Strategy, Observer, Factory, Singleton, Command, Adapter, Facade, Template Method, Iterator, Composite, State, Proxy. Object Oriented design principles, Java/UML");
    controller.updateView();
   }

   private static Scheduler retrieveScheduleFromDatabase(){
      Scheduler new_class = new Scheduler();
      new_class.setClassName("Computer Science I");
      new_class.setClassNumber("135");
      new_class.setClassDescription("Introduction to modern problem solving and programming methods. Emphasis is placed on algorithm development. Introduction to procedural and data abstraction, emphasizing design, testing, and documentation");

      return new_class;
   }
}