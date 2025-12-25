import { Component, signal } from '@angular/core';
import { type InvestmentResultType, type InvestmentFormType } from './investment-form/investment-form.model';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'Investment_Calc';
  // investmentResults: InvestmentResultType[] | null = null;
  investmentResults = signal<InvestmentResultType[] | undefined>(undefined);
}
