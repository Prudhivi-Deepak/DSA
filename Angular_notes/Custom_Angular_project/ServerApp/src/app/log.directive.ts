import { Directive, ElementRef, inject } from '@angular/core';

@Directive({
  selector: '[appLog]',
  standalone: true,
  host: {
    '(click)': 'onLogClick($event)'
  }
})
export class LogDirective {

  private elementRef = inject(ElementRef);

  constructor() { }

  onLogClick(event: MouseEvent) {
    console.log("LogDirective clicked", event);
    console.log("Host element:", this.elementRef.nativeElement);
  }

}
