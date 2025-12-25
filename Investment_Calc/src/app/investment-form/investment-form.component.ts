import { Component, EventEmitter, inject, output, Output, signal } from '@angular/core';
import { type InvestmentFormType } from './investment-form.model';
import { InvestmentService } from './investment.service';

@Component({
  selector: 'app-investment-form',
  templateUrl: './investment-form.component.html',
  styleUrls: ['./investment-form.component.css']
})
export class InvestmentFormComponent {

  principle = signal(10000);
  rate = signal(6);
  time = signal(10);
  contribution = signal(2000);

  private investmentService = inject(InvestmentService);

  // @Output() calculateEventEmitter = new EventEmitter<InvestmentFormType>();
  calculateEventEmitter = output<InvestmentFormType>();

  onCalculateSubmit(){
    this.investmentService.CalculateInvestmentResults({
      initialInvestment: this.principle(),
      annualInvestment: this.contribution(),
      expectedReturn: this.rate(),
      duration: this.time()
    });
    // this.calculateEventEmitter.emit({
    //   initialInvestment: this.principle(),
    //   annualInvestment: this.contribution(),
    //   expectedReturn: this.rate(),
    //   duration: this.time()
    // });
  }
}
