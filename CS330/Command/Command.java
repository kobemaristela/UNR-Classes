
public interface Command {
	public void move(int x, int y, int newX, int newY);
	public void undo();
}
