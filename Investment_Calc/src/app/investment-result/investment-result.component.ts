import { Component, computed, inject, input, Input } from '@angular/core';
import { InvestmentFormType, InvestmentResultType } from '../investment-form/investment-form.model';
import { InvestmentService } from '../investment-form/investment.service';

@Component({
  selector: 'app-investment-result',
  templateUrl: './investment-result.component.html',
  styleUrls: ['./investment-result.component.css']
})
export class InvestmentResultComponent {
  // @Input() investmentData: InvestmentResultType[] | undefined;
  // investmentData = input<InvestmentResultType[] | undefined>();
  private investmentService = inject(InvestmentService);

  investmentData = this.investmentService.getInvestmentResults().asReadonly();

  // investmentData = computed(() => {
  //   return this.investmentService.getInvestmentResults();
  // });

  // get investmentData() {
  //   return this.investmentService.getInvestmentResults();
  // }

}
