public abstract class Tree {
    String description = "Unknown Christmas Tree";
    Boolean isStar = false;

    public String getDescription() {
        return description;
    }

    public abstract int cost();
}
