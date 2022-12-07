
public class NJStore implements SlotMachineStore{
	
	public SlotMachine createStraight() {
		NJPieceFactory nj_factory = new NJPieceFactory();
		SlotMachine slot = nj_factory.createSlotMachine("straight");
		
		return slot;
	}
	
	public SlotMachine createBonus(){
		NJPieceFactory nj_factory = new NJPieceFactory();
		SlotMachine slot = nj_factory.createSlotMachine("bonus");
		
		return slot;
		
	}
	public SlotMachine createProgressive(){
		NJPieceFactory nj_factory = new NJPieceFactory();
		SlotMachine slot = nj_factory.createSlotMachine("progressive");
		
		return slot;
	}
}
