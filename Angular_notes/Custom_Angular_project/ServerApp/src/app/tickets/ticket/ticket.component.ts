import { Component, input, Input, output, signal } from '@angular/core';
import { type Ticket } from '../ticket.model';

@Component({
  selector: 'app-ticket',
  // standalone: true,
  // imports: [],
  templateUrl: './ticket.component.html',
  styleUrl: './ticket.component.css'
})
export class TicketComponent {
  // @Input() ticket!: Ticket;
  data = input.required<Ticket>();
  close = output<string>();
  dataVisible = signal(false);

  onToggledataVisibility() {
    // this.dataVisible.set(!this.dataVisible());
    this.dataVisible.update((visible) => !visible);
    // this.dataVisible.update(visible => !visible);
  }

  onMarkTicketAsClosed() {
    this.close.emit(this.data().id);
  }

}