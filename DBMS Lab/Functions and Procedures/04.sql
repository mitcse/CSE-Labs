-- A

CREATE OR REPLACE PROCEDURE prINt_loan_details (c_id depositor.customer_id%type) is
	CURSOR apCURSOR(id depositor.customer_id%type) is 
	with amounts as( SELECT amount FROM borrower natural joIN loan WHERE customer_id=id),
		payments as( SELECT payment_amount FROM borrower natural joIN payment WHERE customer_id=id)
	SELECT sum(amount) as total_amount, sum(payment_amount) as total_payment FROM amounts, payments;
	a loan.amount%type;
	p payment.payment_amount%type;
BEGIN
	DBMS_OUTPUT.PUT_LINE('Customer : '||c_id);
	open apCURSOR(c_id);
	fetch total_amount,total_payment INto a,p;
	DBMS_OUTPUT.PUT_LINE('Total Amount : '||a||', Total Payment : '||p);
END;
/

-- B

CREATE OR REPLACE PROCEDURE prINt_loan_branch(b_name loan_branch.branch_name%type) is
	CURSOR adCURSOR(name loan_branch.branch_name%type) is 
	with amounts as(SELECT amount FROM loan_branch natural joIN loan WHERE branch_name=name),
		deposits as(SELECT balance FROM account_branch natural joIN account WHERE branch_name=name)
	SELECT sum(amount) as total_amount, sum(balance) as total_deposit FROM amounts, deposits;
	a loan.amount%type;
	d account.balance%type;
BEGIN
	DBMS_OUTPUT.PUT_LINE('Branch : '||b_name);
	open apCURSOR(b_name);
	fetch total_amount,total_deposit INto a,d;
	DBMS_OUTPUT.PUT_LINE('Total Amount : '||a||', Total Deposit : '||d);
END;
/