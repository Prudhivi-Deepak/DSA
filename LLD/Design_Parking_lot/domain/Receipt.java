package LLD.Design_Parking_lot.domain;

import java.time.LocalDateTime;
import java.util.UUID;

public class Receipt {
    private UUID id;
    private UUID ticketId;
    private UUID paymentId;
    private Double amountPaid;
    private LocalDateTime exitTime;
    private STATUS status;
    private enum STATUS {
        SUCCESS, FAILURE, PENDING
    }

    public Receipt(UUID ticketId, UUID paymentId, Double amountPaid) {
        this.id = UUID.randomUUID();
        this.ticketId = ticketId;
        this.paymentId = paymentId;
        this.amountPaid = amountPaid;
        this.exitTime = LocalDateTime.now();
        this.status = STATUS.PENDING;
    }

    // setters and getters
    public UUID getId() {
        return id;
    }

    public UUID getTicketId() {
        return ticketId;
    }

    public UUID getPaymentId() {
        return paymentId;
    }

    public Double getAmountPaid() {
        return amountPaid;
    }

    public LocalDateTime getExitTime() {
        return exitTime;
    }

    public STATUS getStatus() {
        return status;
    }

    // public void setStatus(STATUS status) {
    //     this.status = status;
    // }

    // mark receipt as success
    public void markReceiptSuccess() {
        this.status = STATUS.SUCCESS;
    }

    // mark receipt as failure
    public void markReceiptFailure() {
        this.status = STATUS.FAILURE;
    }

    @Override
    public String toString() {
        return "Receipt{" +
                "id=" + id +
                ", ticketId=" + ticketId +
                ", paymentId=" + paymentId +
                ", amountPaid=" + amountPaid +
                ", exitTime=" + exitTime +
                ", status=" + status +
                '}';
    }
    

}
