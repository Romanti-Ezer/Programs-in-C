#include <stdio.h>
#include <stdlib.h>

int main() {
	char cand_gender, stop;
	int cand_age, i, num_candidates = 0;
	int cand_exp_time, age_m_wexp = 0;
	int amount_f = 0, amount_m = 0, amount_m_wexp = 0;
	float avg_m_wexp_age = 0, smaller_age_f_wexp = 0, percent_m_45older = 0;
	int amount_m_45older = 0, f_35younger_wexp = 0;
	int fem_35younger_wexp = 0, fem_younger_age_wexp = 0;
	
	printf("Candidates Data Survey - Company X\n");
	printf("--------------------------------------\n");
	
	while ((stop != 'y') && (stop != 'Y')){
		num_candidates++;
		printf("\nCandidate %d\n", num_candidates);
		
		printf("Gender [M/F]: ");
		scanf("%s",&cand_gender);
		printf("Age: ");
		scanf("%d",&cand_age);
		printf("Experience time (years): \n");
		scanf("%d",&cand_exp_time);
		
		printf("\n-------------------------------\n");
		
		if ((cand_gender == 'm') || (cand_gender == 'M')){
			amount_m++;
			if (cand_exp_time > 0){
				age_m_wexp += cand_age;
				amount_m_wexp++;
			}
			
			if (cand_age >= 45){
				amount_m_45older++;
			}
		}
		else if ((cand_gender == 'f') || (cand_gender == 'F')){
			amount_f++;
			
			if ((cand_age <= 35) && (cand_exp_time > 0)){
				f_35younger_wexp++;
			}
			
			if(cand_exp_time > 0){
				if (smaller_age_f_wexp == 0){
					smaller_age_f_wexp = cand_age;
				}
				else{
					if (cand_age < smaller_age_f_wexp){
						smaller_age_f_wexp = cand_age;
					}
				}
			}
		}
		
		printf("\nStop? [Y/N]: ");
		scanf("%s",&stop);
		
	}
	
	if (amount_m_wexp != 0){
		avg_m_wexp_age = age_m_wexp / amount_m_wexp;
	}
	
	percent_m_45older = amount_m_45older * 100 / num_candidates;
	
	printf("\nAmount of female candidates: %d\n", amount_f);
	printf("Amount of male candidates: %d\n", amount_m);
	
	printf("\nMale candidates' age average (with experience): %.2f", avg_m_wexp_age);
	printf("\nMale candidates, 45 years old+, percent: %.2f", percent_m_45older);
	
	printf("\nAmount of Female candidates 35 years old (or younger) with exp: %d\n", f_35younger_wexp);
	printf("Younger Female candidate with experience, age: %.2f", smaller_age_f_wexp);
}
