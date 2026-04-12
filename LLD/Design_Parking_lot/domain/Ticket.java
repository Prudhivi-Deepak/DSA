package LLD.Design_Parking_lot.domain;

import java.time.LocalDateTime;
import java.util.UUID;

public class Ticket {
    private UUID id;
    private UUID vehicleId;
    private UUID slotId;
    private LocalDateTime EntryTime;
    private boolean isActive;

    // generate new ticket with constructor
    public Ticket(UUID vehicleID, UUID slotID){
        this.id = UUID.randomUUID();
        this.vehicleId = vehicleID;
        this.slotId = slotID;
        this.EntryTime = LocalDateTime.now();
        this.isActive = true;
    }

    public void deactivate(){
        this.isActive = false;
    }

    public UUID getUUID(){
        return this.id;
    }

    public boolean isActiveTicket(){
        return this.isActive;
    }

    public UUID getVehicleId(){
        return this.vehicleId;
    }

    public UUID getSlotId(){
        return this.slotId;
    }

    public LocalDateTime getEntryTime(){
        return this.EntryTime;
    }

    @Override
    public String toString(){
        return "Ticket{" +
                "id=" + id +
                ", vehicleId=" + vehicleId +
                ", slotId=" + slotId +
                ", entryTime=" + EntryTime +
                ", isActive=" + isActive +
                '}';
    }





}
