package LLD.Design_Parking_lot.domain;

import java.util.UUID;

public class Payment {
    private UUID id;
    private UUID ticketId;
    private Double amount;
    private GateWay gateWay;
    private STATUS status;
    private enum GateWay{
        RASORPAY, STRIPE
    }
    private enum STATUS {
        SUCCESS, FAILURE, PENDING
    }

    public Payment(UUID ticketId, Double amount, GateWay gateWay) {
        this.id = UUID.randomUUID();
        this.ticketId = ticketId;
        this.amount = amount;
        this.gateWay = gateWay;
        this.status = STATUS.PENDING;
    }

    public UUID getId() {
        return id;
    }

    public UUID getTicketId() {
        return ticketId;
    }

    public Double getAmount() {
        return amount;
    }

    public GateWay getGateWay() {
        return gateWay;
    }

    public STATUS getStatus() {
        return status;
    }

    public void setStatus(STATUS status) {
        this.status = status;
    }

    // mark payment as success
    public void markPaymentSuccess() {
        this.status = STATUS.SUCCESS;
    }

    // mark payment as failure
    public void markPaymentFailure() {
        this.status = STATUS.FAILURE;
    }

    @Override
    public String toString() {
        return "Payment{" +
                "id=" + id +
                ", ticketId=" + ticketId +
                ", amount=" + amount +
                ", gateWay=" + gateWay +
                ", status=" + status +
                '}';
    }

}
