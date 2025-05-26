public class SmartDoorLock extends SecurityDevice implements EnergyMonitored {
    private int batteryLevel;
    private boolean doorOpen;
    private static final int MAX_BATTERY = 100;
    
    public SmartDoorLock(String name, String password) {
        super(name, password);
        this.batteryLevel = 100;
        this.doorOpen = false;
    }
    
    @Override
    public double getEnergyConsumption() {
        if (isActive()){
            return 2.5;
        } else {
            return 0.5;
        }
    }
    
    @Override
    public int getEnergyEfficiencyRating() {
        if (batteryLevel <= 20){
            return 1;
        }
        else if (batteryLevel <= 40){
            return 2;
        }
        else if (batteryLevel <= 60){
            return 3;
        }
        else if (batteryLevel <= 80){
            return 4;
        }
        else {
            return 5;
        }
    }
    
    @Override
    public void reportStatus() {
        System.out.println("Smart Door Lock Status:");
        System.out.println("- Name: " + deviceName);
        System.out.println("- Active: " + (isActive() ? "Yes" : "No"));
        System.out.println("- Locked: " + (isLocked() ? "Yes" : "No"));
        System.out.println("- Door Position: " + (doorOpen ? "Open" : "Closed"));
        System.out.println("- Battery Level: " + batteryLevel + "%");
        System.out.println("- Energy Rating: " + getEnergyEfficiencyRating() + "/5");
    }
    
    public void openDoor(String password) {
        if (isDoorOpen()){
            System.out.println("Door is already open");
            return;
        } else if(!isActive()) {
            System.out.println("Cannot open door: Device is not active");
            return;
        } else if (isLocked()) {
            unlock(password);
            if (isLocked()){
            }
        }
        System.out.println("Door opened");
        this.doorOpen = true;
        useBattery(10);
    }
    
    public void closeDoor() {
        if (!isDoorOpen()){
            System.out.println("Door is already closed");
            return;
        } else if (isActive()) {
            lock();
            System.out.println("Door closed");
            useBattery(5);
            this.doorOpen = false;
        } else {
            System.out.println("Door closed");
            useBattery(5);
            this.doorOpen = false;
        }
    }
    
    public boolean isDoorOpen() {
        return this.doorOpen;
    }
    
    public void chargeBattery(int amount) {
        this.batteryLevel += amount;
        if (this.batteryLevel > 100){
            this.batteryLevel = 100;
        }
        System.out.println("Battery charged to " + this.batteryLevel + "%" );
    }
    
    private void useBattery(int amount) {
        this.batteryLevel -= amount;
        if (batteryLevel <= 0) {
            System.out.println("Warning: Battery depleted, device turned off");
            turnOff();
        } else if (batteryLevel < 20){
            System.out.println("Warning: Low battery (" + this.batteryLevel + "%)");
        }
    }
    
    @Override
    public void turnOn() {
        if (batteryLevel <= 0){
            System.out.println("Cannot turn on: Battery depleted");
        } else {
            super.turnOn();
            useBattery(5);
        }
    }
    
    @Override
    public void unlock(String password) {
         if (batteryLevel <= 0){
            System.out.println("Cannot unlock: Battery depleted");
        } else {
            super.unlock(password);
            useBattery(8);
        }
    }
}