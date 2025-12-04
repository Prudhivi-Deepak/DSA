import { afterNextRender, afterRender, AfterViewInit, Component, ElementRef, EventEmitter, OnDestroy, OnInit, Output, viewChild, ViewChild } from '@angular/core';

@Component({
  selector: 'app-new-ticket',
  // standalone: true,
  // imports: [],
  templateUrl: './new-ticket.component.html',
  styleUrl: './new-ticket.component.css'
})
export class NewTicketComponent implements OnInit, AfterViewInit {

  // @ViewChild('formElement') formElement?: ElementRef<HTMLFormElement>;
  formElement = viewChild.required<ElementRef<HTMLFormElement>>('formElement');

  @Output() ticketCreated = new EventEmitter<{title: string, description: string}>();

  constructor() { 
    afterRender(()=>{
      console.log("After Render - New Ticket Component");
    });

    afterNextRender(()=>{
      console.log("After Next Render - New Ticket Component");
    });


  }

  ngOnInit() {
    console.log("OnInit - New Ticket Component");
    console.log(this.formElement()?.nativeElement);
    // console.log(this.formElement?.nativeElement);
  }

  ngAfterViewInit(){
    console.log("AfterViewInit - New Ticket Component");
    // console.log(this.formElement?.nativeElement);
    console.log(this.formElement()?.nativeElement);
  }


  // onSubmit(titleInput: HTMLInputElement) {
  onSubmit(titleInput: string, textAreaInput: string){
    // formElement: HTMLFormElement) {
    console.log('New Ticket Submitted!');
    console.log('Title:', titleInput); 
    console.log('Request:', textAreaInput);
    this.ticketCreated.emit({title: titleInput, description: textAreaInput});
    this.formElement()?.nativeElement.reset();
  }

}
