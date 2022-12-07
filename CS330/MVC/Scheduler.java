public class Scheduler {
  private String className;
  private String classNumber;
  private String classDescription;

  // Getters
  public String getClassName(){
    return className;
  }
    public String getClassNumber(){
    return classNumber;
  }
    public String getClassDescription(){
    return classDescription;
  }
  
  // Setters
  public void setClassName(String name) {
      this.className = name;
  }
  public void setClassNumber(String number) {
      this.classNumber = number;
  }
  public void setClassDescription(String description) {
      this.classDescription = description;
  }

  
}