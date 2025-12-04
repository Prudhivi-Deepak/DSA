import { ComponentFixture, TestBed } from '@angular/core/testing';

import { LifecycleControlComponent } from './lifecycle-control.component';

describe('LifecycleControlComponent', () => {
  let component: LifecycleControlComponent;
  let fixture: ComponentFixture<LifecycleControlComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [LifecycleControlComponent]
    })
    .compileComponents();
    
    fixture = TestBed.createComponent(LifecycleControlComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
