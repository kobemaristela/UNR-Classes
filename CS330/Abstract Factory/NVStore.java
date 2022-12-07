
public class NVStore implements SlotMachineStore{
	
	public SlotMachine createStraight() {
		NVPieceFactory nv_factory = new NVPieceFactory();
		SlotMachine slot = nv_factory.createSlotMachine("straight");
		
		return slot;
	}
	
	public SlotMachine createBonus(){
		NVPieceFactory nv_factory = new NVPieceFactory();
		SlotMachine slot = nv_factory.createSlotMachine("bonus");
		
		return slot;
		
	}
	public SlotMachine createProgressive(){
		NVPieceFactory nv_factory = new NVPieceFactory();
		SlotMachine slot = nv_factory.createSlotMachine("progressive");
		
		return slot;
	}
}
