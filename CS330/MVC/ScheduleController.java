public class ScheduleController {
  private Scheduler model;
  private ScheduleView view;

  public ScheduleController(Scheduler model, ScheduleView view) {
    this.model = model;
    this.view = view;
  }

  public void setClassName(String name){
      model.setClassName(name);		
   }

   public String getClassName(){
      return model.getClassName();		
   }

  public void setClassNumber(String number){
      model.setClassNumber(number);		
   }

   public String getClassNumber(){
      return model.getClassNumber();		
   }

    public void setClassDescription(String description){
      model.setClassDescription(description);		
   }

   public String getClassDescription(){
      return model.getClassDescription();		
   }

   public void updateView(){				
      view.printSchedule(model.getClassName(), model.getClassNumber(), model.getClassDescription());
   }	
}