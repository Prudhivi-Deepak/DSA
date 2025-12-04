import { Component } from '@angular/core';
import { Ticket } from '../tickets/ticket.model';

@Component({
  selector: 'app-support-tickets',
  // standalone: true,
  standalone: false,
  // imports: [],
  templateUrl: './support-tickets.component.html',
  styleUrl: './support-tickets.component.css'
})
export class SupportTicketsComponent {
  tickets: Ticket[] = [];

  onTicketCreated(ticketData: {title: string, description: string}) {
    console.log('Ticket created event received in SupportTicketsComponent:', ticketData);
    const ticket: Ticket = {
      id: Math.floor(Math.random() * 10000).toString(),
      title: ticketData.title,
      request: ticketData.description,
      status: 'open',
      // createdAt: new Date()
    };
    console.log('New Ticket Object:', ticket);
    this.tickets.push(ticket);
  }

  OnCloseSupportTicket(ticketId: string) {
    this.tickets = this.tickets.map(ticket => {
      if (ticket.id === ticketId) {
        return {
          ...ticket,
          status: 'closed'
        };
      }
      return ticket;
    });
  }

}