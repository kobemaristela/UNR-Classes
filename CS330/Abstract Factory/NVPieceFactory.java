
public class NVPieceFactory implements SlotMachinePieceFactory{
		
	public SlotMachine createSlotMachine (String slot_type) {
		
		SlotMachine slot = null;

		
		if (slot_type.equals("straight")) 
		{
			slot = new StraightSlot();
			
			slot.cabinet = new LargeCabinet();
			slot.display = new ReelsDisplay();
			slot.payment = new TicketPayment();
			slot.cpu = new ArmCPU();
			slot.os = new LinuxOS();
		}
		else if (slot_type.equals("progressive")) 
		{
			slot = new ProgressiveSlot();
			
			slot.cabinet = new MediumCabinet();
			slot.display = new LCDDisplay();
			slot.payment = new TicketPayment();
			slot.cpu = new X86CPU();
			slot.os = new AndroidOS();
		} 
		else if (slot_type.equals("bonus")) 
		{
			slot = new BonusSlot();
			
			slot.cabinet = new SmallCabinet();
			slot.display = new CRTDisplay();
			slot.payment = new TicketPayment();
			slot.cpu = new X86CPU();
			slot.os = new LinuxOS();
		}
		
		return slot;
	}
}
