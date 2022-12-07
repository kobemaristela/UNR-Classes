
public class NJBigFactory extends BIGFactory{

	public SlotMachine createSlotMachine (String slot_type) {
		if (slot_type.equals("straight")) {
			return new NJStraightSlot();
		} else if (slot_type.equals("progressive")) {
			return new NJProgressiveSlot();
		} else if (slot_type.equals("bonus")) {
			return new NJBonusGameSlot();
		} else return null;
	}
}
