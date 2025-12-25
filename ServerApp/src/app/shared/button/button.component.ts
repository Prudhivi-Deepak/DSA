import { Component, input, Input } from '@angular/core';

@Component({
  // selector: 'app-button',
  selector: 'button[appButton], a[appButton]',
  // standalone: true,
  // imports: [],
  templateUrl: './button.component.html',
  styleUrl: './button.component.css'
})
export class ButtonComponent {
  // @Input({required : true}) buttonLabel! : string;
  // @Input({required : false}) buttonIcon! : string;
  // buttonLabel = input.required<string>();
  // buttonIcon = input.required<string>();
}
