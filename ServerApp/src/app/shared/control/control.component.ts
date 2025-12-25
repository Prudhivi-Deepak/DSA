import { AfterContentInit, Component, contentChild, ContentChild, ElementRef, HostBinding, HostListener, inject, input, ViewEncapsulation } from '@angular/core';

@Component({
  selector: 'app-control',
  // standalone: true,
  // imports: [],
  templateUrl: './control.component.html',
  styleUrl: './control.component.css',
  encapsulation: ViewEncapsulation.None,
  host: {
    class: 'control',
    '(click)': 'onClick()'
  }
})
export class ControlComponent implements AfterContentInit{
  // @HostBinding('class') classControl = 'control';
  // @HostListener('click') 
  private Eref = inject(ElementRef);

  // @ContentChild('input') userinput?: ElementRef<HTMLInputElement | HTMLTextAreaElement>;
  private userinput = contentChild.required<ElementRef<HTMLInputElement | HTMLTextAreaElement>>('input');

  ngAfterContentInit(){
    console.log('Content Child:', this.userinput);
  }

  onClick() {
    console.log(this.Eref);
    console.log('Control component clicked!');
    console.log(this.userinput()?.nativeElement);
  }
  titleLabel = input.required<string>();
}
