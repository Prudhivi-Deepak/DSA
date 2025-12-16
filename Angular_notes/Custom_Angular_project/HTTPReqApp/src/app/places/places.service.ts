import { inject, Injectable, signal } from '@angular/core';
import { Place } from './place.model';
import { HttpClient } from '@angular/common/http';
import { catchError, map, tap, throwError } from 'rxjs';
import { ErrorService } from '../shared/error.service';

@Injectable({
  providedIn: 'root',
})
export class PlacesService {
  private errorService = inject(ErrorService)
  private httpClient = inject(HttpClient);
  private userPlaces = signal<Place[]>([]);
  
  loadedUserPlaces = this.userPlaces.asReadonly();

  loadAvailablePlaces() {
    return this.fetchPlaces('http://localhost:3000/places', 'Failed to load available places.');
  }

  loadUserPlaces() {
    return this.fetchPlaces('http://localhost:3000/user-places', 'Failed to load user places.').pipe(tap({
      next: (places) => {
        this.userPlaces.set(places || []);
      }
    }))
  }

  addPlaceToUserPlaces(place: Place) {
    const prevPlace = this.userPlaces(); // storing previous values incase of error to revert back
    // this.userPlaces.update((currentPlaces) => { return [...currentPlaces, place]; });
    if(!this.userPlaces().some(p=>p.id==place.id)){
      this.userPlaces.set([...prevPlace, place]);
    }
    return this.httpClient.put('http://localhost:3000/user-places/', {
      placeId: place.id
    }).pipe(
      catchError(
        (error) => {
          this.userPlaces.set(prevPlace);// reverting back to previous state in case of error
          this.errorService.showError('Failed to add place to user places.');
          return throwError(() => new Error('Failed to add place to user places.'));
        })
    );
  }

  removeUserPlace(place: Place) { 
    const prevPlace = this.userPlaces(); // storing previous values incase of error to revert back
    // this.userPlaces.update((currentPlaces) => { return [...currentPlaces, place]; });
    if(this.userPlaces().some(p=>p.id==place.id)){ // any true value return true value / delete the value if found
      // this.userPlaces.set([...prevPlace, place]);
      this.userPlaces.set(prevPlace.filter(p=>p.id!==place.id));
    }
    return this.httpClient.delete('http://localhost:3000/user-places/'+place.id).pipe(
      catchError(
        (error) => {
          this.userPlaces.set(prevPlace);// reverting back to previous state in case of error
          this.errorService.showError('Failed to delete place to user places.');
          return throwError(() => new Error('Failed to delete place to user places.'));
        })
    );
  }

  private fetchPlaces(url: string, errorMessage: string) {
    return this.httpClient.get<{ places: Place[] }>(url, {
      observe: 'response',
      // observe: 'events'
    }).pipe(
      map(((response) => { return response.body?.places })),
      catchError((error) => {
        console.log(error);
        return throwError(() => {
          return new Error(errorMessage);
        })
      })
    )
  }
}


