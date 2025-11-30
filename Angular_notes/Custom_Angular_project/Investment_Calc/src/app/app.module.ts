import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { InvestmentFormComponent } from './investment-form/investment-form.component';
import { FormsModule } from '@angular/forms';
import { InvestmentResultComponent } from './investment-result/investment-result.component';

@NgModule({
  declarations: [
    AppComponent,
    InvestmentFormComponent,
    InvestmentResultComponent
  ],
  imports: [
    BrowserModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
