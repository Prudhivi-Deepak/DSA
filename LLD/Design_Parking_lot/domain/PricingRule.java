package LLD.Design_Parking_lot.domain;

import java.util.UUID;

public class PricingRule {
    
    private UUID id;
    private Double ratePerHour;
    private Double flatRate;
    // private RuleType ruleType;
    private VehicleType vehicleType;
    public enum VehicleType {
        BIKE, CAR, TRUCK, EV
    };
    // public enum RuleType {
    //     FLAT, HOURLY
    // }

    public PricingRule(Double ratePerHour, Double flatRate, VehicleType vehicleType) {
        this.id = UUID.randomUUID();
        this.ratePerHour = ratePerHour;
        this.flatRate = flatRate;
        // this.ruleType = ruleType;
        this.vehicleType = vehicleType;
    }

    // Getters and Setters
    public UUID getId() {
        return id;
    }

    public Double getRatePerHour() {
        return ratePerHour;
    }

    public void setRatePerHour(Double ratePerHour) {
        this.ratePerHour = ratePerHour;
    }

    public Double getFlatRate() {
        return flatRate;
    }

    public void setFlatRate(Double flatRate) {
        this.flatRate = flatRate;
    }

    public void setFlatRateAndRatePerHour(Double flatRate, Double ratePerHour) {
        this.flatRate = flatRate;
        this.ratePerHour = ratePerHour;
    }

    public VehicleType getVehicleType() {
        return vehicleType;
    }

    @Override
    public String toString() {
        return "PricingRule{" +
                "id=" + id +
                ", ratePerHour=" + ratePerHour +
                ", flatRate=" + flatRate +
                ", vehicleType=" + vehicleType +
                '}';
    }

}
