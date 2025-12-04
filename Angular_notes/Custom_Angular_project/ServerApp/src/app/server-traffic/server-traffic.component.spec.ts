import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ServerTrafficComponent } from './server-traffic.component';

describe('ServerTrafficComponent', () => {
  let component: ServerTrafficComponent;
  let fixture: ComponentFixture<ServerTrafficComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [ServerTrafficComponent]
    })
    .compileComponents();
    
    fixture = TestBed.createComponent(ServerTrafficComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
