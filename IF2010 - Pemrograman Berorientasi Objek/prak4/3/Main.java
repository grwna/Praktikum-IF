public class Main {
    public static void main(String[] args) {
        SmartDoorLock p1 = new SmartDoorLock("AkuTau", "2");
        SmartDoorLock p2 = new SmartDoorLock("Alice", "2");
        p1.chargeBattery(100);
        p2.chargeBattery(23);
        p1.unlock("2");
        p1.turnOn();
        p1.lock();
        p1.openDoor("3");
        p1.openDoor("2");
        p2.getEnergyConsumption();
        p1.reportStatus();
        p2.reportStatus();
    }
}   